#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct s{
	int maxx;
	int nexx;
	int fen; 
};
int t,n;
int a[N][4];
s b[N];//存储所有人的maxx和minn； 
int num[4];//每个部门人数 
int cun1[N];//存储部门分配同学；
int cun2[N];
int cun3[N];
priority_queue<int,vector<int>,greater<int> >zui;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(num,0,sizeof(num));
		while(!zui.empty()){
			zui.pop();
		}
		int ans=0;
		int ans2;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]>a[i][2]){
				if(a[i][1]>a[i][3]){
					b[i].fen=1;
					b[i].maxx=a[i][1];
					b[i].nexx=a[i][1]-max(a[i][2],a[i][3]); 
				}
				else{
					b[i].fen=3;
					b[i].maxx=a[i][3]; 
					b[i].nexx=a[i][3]-a[i][1];
				}
			}
			else{
				if(a[i][2]>a[i][3]){
					b[i].fen=2;
					b[i].maxx=a[i][2];
					b[i].nexx=a[i][2]-max(a[i][1],a[i][3]); 
				}
				else{
					b[i].fen=3;
					b[i].maxx=a[i][3];
					b[i].nexx=a[i][3]-a[i][2];
				}
			}
		}
		int pan,set;//判断哪个部门满员，分了几个； 
		for(int i=1;i<=n;i++){
			num[b[i].fen]++;
			if(b[i].fen==1){
				cun1[num[b[i].fen]]=b[i].nexx;
			}
			else if(b[i].fen==2){
				cun2[num[b[i].fen]]=b[i].nexx;
			}
			else{
				cun3[num[b[i].fen]]=b[i].nexx;
			}
			ans+=b[i].maxx; 
			if(n>=n/2){
				int pan2=false;
				for(int j=1;j<=3;j++){
					if(num[j]>=n/2){
						pan=j;
						set=i;
						pan2=true;
						break;
					}
				}
				if(pan2){
					break;
				}
			}
		}
		if(pan==1){
			for(int j=1;j<=set;j++){
				zui.push(cun1[j]);
			}
		} 
		else if(pan==2){
			for(int j=1;j<=set;j++){
				zui.push(cun2[j]);
			}
		}
		else{
			for(int j=1;j<=set;j++){
				zui.push(cun3[j]);
			}
		}
		int n2=n/2;
		for(int i=set+1;i<=n;i++){
			if(b[i].fen==pan){
				int c=zui.top();
				if(b[i].maxx>c){
					zui.pop();
					zui.push(b[i].maxx);
					ans+=b[i].maxx-c;
				}
				else{
					ans+=b[i].maxx-b[i].nexx;
				}
			}
			else{
				ans+=b[i].maxx;
			}
		}
		cout<<ans<<endl; 
	}
	return 0;
}
/*/3
4 
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0*/
