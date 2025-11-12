#include<bits/stdc++.h>

using namespace std;

const int kMaxN=1e5+1;

int t,n;
int ans,cnt[3];
int club[3][kMaxN];
struct stu{
	int a,b,c;
	int secx(){
		return min({max(a,b),max(b,c),max(c,a)});
	}
	int maxx(){
		if(a>=max(b,c)){
			club[0][cnt[0]++]=a-secx();
			return a;
		}else if(b>=c){
			club[1][cnt[1]++]=b-secx();
			return b;
		}else{
			club[2][cnt[2]++]=c-secx();
			return c;
		}
	}
}num[kMaxN];

int main(){
	ifstream cin("club.in");
	ofstream cout("club.out");
	ios_base::sync_with_stdio(0);
	for(cin>>t;t--;){
		memset(cnt,0,sizeof(cnt));
		memset(club,0,sizeof(club));
		ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>num[i].a>>num[i].b>>num[i].c;
			ans+=num[i].maxx();
		}
		for(int i=0;i<3;i++){
			sort(club[i],club[i]+cnt[i]);
			for(int j=0;cnt[i]-j>n/2;j++){
				ans-=club[i][j];
			}
		}
		cout<<ans<<'\n';
	}
	return 0; 
}
