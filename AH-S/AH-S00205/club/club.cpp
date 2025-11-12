#include<bits/stdc++.h>
using namespace std;  
const int N=2e5+5;
int a[N][4],t[4],mx[N],mx2[N],mxid[N],mx2id[N],c[N]; 
int check(int n){
    if(t[1]>n/2){
		return 1;
	}
	if(t[2]>n/2){
		return 2;
	}
	if(t[3]>n/2){
       return 3;
	}  
	return 0;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout); 
    int TT,n;
    cin>>TT;
    while(TT--){
	    cin>>n;
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=3;j++){
		        cin>>a[i][j];
	    	}
	    }
	    int ans=0;
	    for(int i=1;i<=3;i++){
	        t[i]=0;
	    }
		for(int i=1;i<=n;i++){
		    mx[i]=mx2[i]=-1;
		    mxid[i]=mx2id[i]=0;
		    for(int j=1;j<=3;j++){
			    if(a[i][j]>mx[i]){
				    mx2[i]=mx[i];
				    mx2id[i]=mxid[i];
				    mx[i]=a[i][j];
				    mxid[i]=j;
				}else{
					if(a[i][j]>mx2[i])
                    {
					     mx2[i]=a[i][j];
					     mx2id[i]=j;
					}
				}
			}
			t[mxid[i]]++;
			ans+=mx[i];
		}
		int mxcnt=max(max(t[1],t[2]),t[3]);
		if(mxcnt<=n/2){
		    cout<<ans<<"\n";
		}else{
		    int id=check(n); 
			int len=0;
			for(int i=1;i<=n;i++){
				if(mxid[i]==id){
				    ++len;
				    c[len]=mx[i]-mx2[i];
				}
			}
			sort(c+1,c+len+1);
			for(int i=1;i<=mxcnt-n/2;i++){
			    ans-=c[i];
			}
			cout<<ans<<"\n";
		} 
	}
    return 0;
}
//Ren5Jie4Di4Ling5%
