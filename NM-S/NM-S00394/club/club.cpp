#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fo(i,a,b) for(ll i=(a);i<=(b);i++)
using namespace std;
const ll N=1e5+10;
ll a[N],n,t,sum;
struct node{
	ll num,id;
}b[N][5];
pair<ll,ll> x[5][N];//xx专业的i人的第j专业 
pair<ll,ll> mi[5],mi2[5];//当前各部门跳槽最不影响的人 
ll siz[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		fo(i,1,3)mi[i].first=mi2[i].first=0x3f3f3f3f,mi[i].second=mi2[i].second=0,siz[i]=0;
		fo(i,1,3)fo(j,1,n)x[i][j]={0,0};
		sum=0;
		fo(i,1,n)fo(j,1,3)cin>>b[i][j].num,b[i][j].id=j;
		fo(i,1,n){
			fo(j,1,3)fo(k,1,3)if(b[i][k].num<b[i][k+1].num)swap(b[i][k],b[i][k+1]);
			ll k=b[i][1].id;//k表示当前挑战者第一志愿 
			if(siz[k]==n/2){
				//准备pk
				ll las=mi[k].second;
				if(sum<sum-b[x[k][las].first][x[k][las].second].num+b[i][1].num+b[x[k][las].first][x[k][las].second+1].num){
					mi[k]=mi2[k];//回溯 
					sum=sum-b[x[k][las].first][x[k][las].second].num+b[i][1].num+b[x[k][las].first][x[k][las].second+1].num;
					ll lask=b[las][2].id;//lask:第las人的下一个专业 
					if(mi[k].first>b[i][1].num-b[i][2].num){
						if(mi2[k].first>mi[k].first){
							mi2[k].first=mi[k].first;
							mi2[k].second=mi[k].second;
						}
						mi[k].first=b[i][1].num-b[i][2].num;
						mi[k].second=i;
					}
					x[lask][las]={las,2};
					if(mi[lask].first>b[las][2].num-b[las][3].num){
						if(mi2[lask].first>mi[lask].first){
							mi2[lask].first=mi[lask].first;
							mi2[lask].second=mi[lask].second;
						}
						mi[lask].first=b[las][2].num-b[las][3].num;
						mi[lask].second=las;
					}
					siz[lask]++;
				}else{
					k=b[i][2].id;
					x[k][i]={i,2};
					siz[k]++;
					sum+=b[i][2].num;
					if(mi[k].first>b[i][2].num-b[i][3].num){
						if(mi2[k].first>mi[k].first){
							mi2[k].first=mi[k].first;
							mi2[k].second=mi[k].second;
						}
						mi[k].first=b[i][2].num-b[i][3].num;
						mi[k].second=i;
					}
				}
			}else{
				x[k][i]={i,1};
				sum+=b[i][1].num;
				siz[k]++;
				if(mi[k].first>b[i][1].num-b[i][2].num){
					if(mi2[k].first>mi[k].first){
						mi2[k].first=mi[k].first;
						mi2[k].second=mi[k].second;
					}
					mi[k].first=b[i][1].num-b[i][2].num;
					mi[k].second=i;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
