#include<bits/stdc++.h>
using namespace std;
struct man{
	int w1;
	int w2;
	int w3;
	int top;
	int cha;
	int highest;
}br[100001];
struct akm{
	int aug;
	int awm;
};
bool cmp(akm x,akm y){
	return x.awm>y.awm;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		int u1=0,u2=0,u3=0;
		for(int i=1;i<=n;i++){
			cin>>br[i].w1>>br[i].w2>>br[i].w3;
			if(br[i].w1>=br[i].w2&&br[i].w1>=br[i].w3){
				u1++;
				br[i].top=1;
				br[i].highest=br[i].w1;
			}
			if(br[i].w2>=br[i].w1&&br[i].w2>=br[i].w3){
				u2++;
				br[i].top=2;
				br[i].highest=br[i].w2;
			}
			if(br[i].w3>=br[i].w1&&br[i].w3>=br[i].w2){
				u3++;
				br[i].top=3;
				br[i].highest=br[i].w3;
			}
			br[i].cha=br[i].highest*2-br[i].w1-br[i].w2-br[i].w3+min(min(br[i].w1,br[i].w2),br[i].w3);
		}
		long long ys=0;
		//cout<<u1<<" "<<u2<<" "<<u3<<endl;
		if(u1<=n/2&&u2<=n/2&&u3<=n/2){
			for(int i=1;i<=n;i++){
				ys+=br[i].highest;
			}
			cout<<ys<<endl;
			continue;
		}
		else{
			bool b[100001];
			for(int i=1;i<=n;i++) b[i]=0;
			int big;
			if(u1>=u2&&u1>=u3) big=1;
			else if(u2>=u1&&u2>=u3) big=2;
			else big=3;
			akm ak[100001];
			int cur=0;
			for(int i=1;i<=n;i++){
				if(br[i].top==big){
					cur++;
					ak[cur].aug=i;
					ak[cur].awm=br[i].cha;
					b[i]=1;
				}
			}
			sort(ak+1,ak+cur+1,cmp);
			for(int i=1;i<=int(n/2);i++) b[ak[i].aug]=0;
			long long ys=0;
			for(int i=1;i<=n;i++){
				//cout<<b[i]<<" ";
				if(b[i]==0) ys+=br[i].highest;
				else ys+=br[i].highest-br[i].cha;
			}
			cout<<ys<<endl;
			continue;
		}
	}
	return 0;
} 
