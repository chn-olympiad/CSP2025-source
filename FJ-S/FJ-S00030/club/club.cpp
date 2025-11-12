#include<bits/stdc++.h>
using namespace std;
const int N=100007;

int T,n,in1,in2,in3,t[4],ans[4],p,q1,q2;
struct team{
	int x[4];
}b[4][N];
bool cmp(team b1,team b2){
	return b1.x[p]-max(b1.x[q1],b1.x[q2]) >= b2.x[p]-max(b2.x[q1],b2.x[q2]);
}
bool cmp1(team b1,team b2){
	return b1.x[q1]-b1.x[q2] >= b2.x[q1]-b2.x[q2];
}
bool cmp2(team b1,team b2){
	return b1.x[q2]-b1.x[q1] >= b2.x[q2]-b2.x[q1];
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(b,0,sizeof b);
		memset(t,0,sizeof t);
		memset(ans,0,sizeof ans);
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&in1,&in2,&in3);
			if(in1>=in2 && in1>=in3)b[1][++t[1]]={{0,in1,in2,in3}},ans[1]+=in1;
			else if(in2>=in1 && in2>=in3)b[2][++t[2]]={{0,in1,in2,in3}},ans[2]+=in2;
			else b[3][++t[3]]={{0,in1,in2,in3}},ans[3]+=in3;
		}
		if(t[1]>n/2)p=1,q1=2,q2=3;
		else if(t[2]>n/2)p=2,q1=1,q2=3;
		else if(t[3]>n/2)p=3,q1=1,q2=2;
		else p=0;
		if(p){
			sort(b[p]+1,b[p]+t[p]+1,cmp);
			for(int i=n/2+1;i<=t[p];i++){
				//cout<<b[p][i].x[p]<<endl;
				ans[p]-=b[p][i].x[p];
				if(b[p][i].x[q1] >= b[p][i].x[q2]){
					ans[q1]+=b[p][i].x[q1];
					b[q1][++t[q1]]=b[p][i];
				}else{
					ans[q2]+=b[p][i].x[q2];
					b[q2][++t[q2]]=b[p][i];
				}
			}
			if(t[q1]>n/2){
				sort(b[q1]+1,b[q1]+t[q1]+1,cmp1);
				for(int i=n/2+1;i<=t[q1];i++){
					ans[q1]-=b[p][i].x[q1];
					ans[q2]+=b[p][i].x[q2];
					b[q2][++t[q2]]=b[q1][i];
				}
			}else if(t[q2]>n/2){
				sort(b[q2]+1,b[q2]+t[q2]+1,cmp2);
				for(int i=n/2+1;i<=t[q2];i++){
					ans[q2]-=b[p][i].x[q2];
					ans[q1]+=b[p][i].x[q1];
					b[q1][++t[q1]]=b[q2][i];
				}
			}
		}
		cout<<(ans[1]+ans[2]+ans[3])<<endl;
	}
	return 0;
}
