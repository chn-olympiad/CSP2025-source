//GZ-S00316 毕节东辰实验学校 王子晨 
#include <bits/stdc++.h>
using namespace std;
int fd1(int a,int b,int c){
	if(a>=b&&a>=c){
		return 1;
	}
	if(b>=a&&b>=c){
		return 2;
	}
	if(c>=a&&c>=a){
		return 3;
	}
}
int fd2(int a,int b,int c){
	if(b>=a&&a>=c){
		return 1;
	}
	if(c>=a&&a>=b){
		return 1;
	}
	if(a>=b&&b>=c){
		return 2;
	}
	if(c>=b&&b>=a){
		return 2;
	}
	if(b>=c&&c>=a){
		return 3;
	}
	if(a>=c&&c>=b){
		return 3;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int> > s(n+1,vector<int>(4,0));
		int ans=0;
		int cnt[4]={0,0,0,0};
		int over=0;
		vector<vector<int> > cia(4,vector<int>(20001,0));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>s[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			int fir=fd1(s[i][1],s[i][2],s[i][3]);
			int sec=fd2(s[i][1],s[i][2],s[i][3]);
			if(over!=fir){
				cnt[fir]++;
				ans+=s[i][fir];
				cia[fir][s[i][fir]-s[i][sec]]++;
				if(cnt[fir]==n/2){
					over=fir;
				}
			}else{
				for(int j=0;j<=20000;j++){
					if(cia[fir][j]>0){
						if(s[i][fir]-s[i][sec]>j){
							ans+=s[i][fir]-j;
							cia[fir][s[i][fir]-s[i][sec]]++;
							cia[fir][j]--;
							break;
						}else{
							ans+=s[i][sec];
							break;
						} 
					}
				}
			}	
		} 
		cout<<ans<<endl;
	}
	return 0;
}
