#include<iostream>
#include<algorithm>
#include<vector>
//#define int long long
using namespace std;

const int N=5e4+10;

bool cmp(vector<int> a,vector<int> b){
	if(a[0]!=b[0])return a[0]>b[0];
	return a[4]>b[4];
}

int n,cou[4],ans;
vector<int> a[2*N],no;

bool cmp1(int x,int y){
	return (a[x][4])>(a[y][4]);
}

signed main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;
	for(int i=1;i<2*N;i++)a[i].push_back(0),a[i].push_back(0),a[i].push_back(0),a[i].push_back(0),a[i].push_back(0);
	while(t--){
		cin>>n;
		ans=0;
		no.clear();
		cou[1]=n,cou[2]=0,cou[3]=0;
		for(int i=1,num;i<=n;i++){
			for(int j=1;j<4;j++){
				cin>>a[i][j];
			}
			ans+=a[i][1];
			a[i][0]=max(a[i][2],a[i][3])-a[i][1];
			a[i][4]=min(a[i][2],a[i][3])-a[i][1];
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i][0]<=0&&cou[1]<=n/2)break;
			if(a[i][2]>a[i][3]){
				if(cou[2]<n/2){
					cou[2]++;
					ans+=(a[i][2]-a[i][1]);
					cou[1]--;
				}else{
					if(a[i][4]>0){
						cou[3]++;
						ans+=(a[i][3]-a[i][1]);
						cou[1]--;continue;
					}
					no.push_back(i);
					continue;
				}
			}else if(a[i][2]==a[i][3]){
				if(a[i][0]<=0){
					no.push_back(i);
					continue;
				}
				if(cou[2]<n/2){
					cou[2]++;
					ans+=(a[i][2]-a[i][1]);
					cou[1]--;
				}else{
					cou[3]++;
					ans+=(a[i][3]-a[i][1]);
					cou[1]--;
				}
			}else{
				if(cou[3]<n/2){
					cou[3]++;
					ans+=(a[i][3]-a[i][1]);
					cou[1]--;
				}else{
					if(a[i][4]>0){
						cou[2]++;
						ans+=(a[i][2]-a[i][1]);
						cou[1]--;
					}
					no.push_back(i);
					continue;
				}
			}
		}
		if((cou[1])>n/2){
			int j=0;
			sort(no.begin(),no.end(),cmp1);
			while((cou[1])>n/2){
				cou[1]--;
				ans+=(a[no[j]][4]),j++;
			}
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
}
