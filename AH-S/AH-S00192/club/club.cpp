#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int n,t,edgen,sum1,sum2,maxn,pos,dpos;
int a[100005][5],flagi;
bool vis[100005][5],tmpflag2,tmpflag3;

struct ggvb{
	int b,c;
}m[100005];

void dfs(int pos,int ren1,int ren2,int ren3,int t1,int t2,int t3){
	//cout<<pos<<" "<<ren1<<" "<<ren2<<" "<<ren3<<" "<<t1<<" "<<t2<<" "<<t3<<endl;
	if(ren1+ren2+ren3==n){
		maxn=max(maxn,t1+t2+t3);
		//cout<<"new maxn\n";
		return ;
	}
	if(t1+t2+t3>=maxn&&maxn!=-1){
		//cout<<"cut over\n";
		return ;
	}
	for(int i=1;i<=flagi;i++){
		int tmp1=0,tmp2=0,tmp3=0;
		if(i==1) tmp1=1;
		else if(i==2) tmp2=1;
		else tmp3=1;
		if(!vis[pos][i]&&ren1+tmp1<=edgen&&ren2+tmp2<=edgen&&ren3+tmp3<=edgen){
			vis[pos][i]=1;
			int tmp4=0,tmp5=0,tmp6=0;
			if(i==1) tmp4=a[pos][i];
			else if(i==2) tmp5=a[pos][i];
			else tmp6=a[pos][i];
			dfs(pos+1,ren1+tmp1,ren2+tmp2,ren3+tmp3,t1+tmp4,t2+tmp5,t3+tmp6);
			vis[pos][i]=0;
		}
	}
	return ;
}

bool cmp1(ggvb x,ggvb y){
	return x.b>y.b;
}

bool cmp2(ggvb x,ggvb y){
	if(x.b==y.b) return x.c>y.c;
	if(x.c==y.c) return x.b>y.b;
	return max(x.b,x.c)>max(y.b,y.c);
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        }
        tmpflag2=tmpflag3=1;
        flagi=3;
        for(int i=1;i<=n;i++){
            if(a[i][2]!=0){
				tmpflag2=0;
			}
			if(a[i][3]!=0){
				tmpflag3=0;
			}
        }
        if(tmpflag2&&tmpflag3){//A
			for(int i=1;i<=n;i++) m[i].b=a[i][1];
			sort(m+1,m+n+1,cmp1);
			maxn=0;
			for(int i=1;i<=n/2;i++){
				maxn+=a[i][1];
			}
			cout<<maxn<<endl;
			continue;
		}else if(tmpflag3){//B
			flagi=2;
		}
		//normal
        edgen=n/2;
        maxn=-1;
		dfs(1,0,0,0,0,0,0);
		cout<<maxn<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
