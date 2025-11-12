#include<bits/stdc++.h>
using namespace std;
struct node{
    int st1,nd2,rd3;
    int x[4];
}a[100005],b[100005];
int T,n,ma,f[25];
bool cmp(node al,node bl){
    if(al.x[al.st1]!=bl.x[bl.st1]){
        return al.x[al.st1]<bl.x[bl.st1];
    }else{
        return al.st1<bl.st1;
    }
}
bool cmp2(node al,node bl){
    if(al.x[al.st1]!=bl.x[bl.st1]){
        return al.x[al.st1]>bl.x[bl.st1];
    }else{
        return al.st1<bl.st1;
    }
}
void dfs(int u,int A,int b,int c){
	if(u==n+1){
		int ss=0;
		for(int i=1;i<=n;i++){
			ss+=a[i].x[f[i]];
		}
		ma=max(ma,ss);
	}
	if(A!=n/2){
		f[u]=1;
		dfs(u+1,A+1,b,c);
	}
	if(b!=n/2){
		f[u]=2;
		dfs(u+1,A,b+1,c);
	}
	if(c!=n/2){
		f[u]=3;
		dfs(u+1,A,b,c+1);
	}
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        int ttt=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i].x[j];
            }
            if(a[i].x[2]!=0||a[i].x[3]!=0){
            	ttt=0;
            }
            int x1=a[i].x[1],x2=a[i].x[2],x3=a[i].x[3];
            int ma=max(max(x1,x2),x3),mi=min(min(x1,x2),x3);
            if(x1==ma){
                a[i].st1=1;
            }else if(x2==ma){
                a[i].st1=2;
            }else{
                a[i].st1=3;
            } 
            if(x1==mi&&a[i].st1!=1){
                a[i].rd3=1;
            }else if(x2==mi&&a[i].st1!=2){
                a[i].rd3=2;
            }else{
                a[i].rd3=3;
            } 
            a[i].nd2=6-a[i].st1-a[i].rd3;
            b[i]=a[i];
        }
        if(n<=20){
        	dfs(1,0,0,0);
        	cout<<ma;
        }else if(!ttt){
   	    	sort(a+1,a+n+1,cmp);
    	    sort(b+1,b+n+1,cmp2);
    	    int ans=0,s[4]={0,0,0,0};
    	    for(int i=1;i<=n;i++){
    	        if(s[a[i].st1]==n/2){
    	            ans+=a[i].x[a[i].nd2];
    	            s[a[i].nd2]++;
    	        }else{
    	            ans+=a[i].x[a[i].st1];
    	            s[a[i].st1]++;
    	        }
    	    }
    	    int ans2=0,s2[4]={0,0,0,0};
    	    for(int i=1;i<=n;i++){
    	        if(s2[b[i].st1]==n/2){
    	            ans2+=b[i].x[b[i].nd2];
    	            s2[b[i].nd2]++;
	            }else{
    	            ans2+=b[i].x[b[i].st1];
    	            s2[b[i].st1]++;
    	        }
    	    }
	        cout<<max(ans,ans2)<<"\n";
        }else{
        	int ans=0;
        	sort(a+1,a+n+1,cmp2);
        	for(int i=1;i<=n/2;i++){
        		ans+=a[i].x[1];
        	}
        	cout<<ans<<"\n";
        }
    }
    return 0;
}
