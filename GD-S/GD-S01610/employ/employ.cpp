#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[30];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==10){
		int count;
		int ans=0;
		int people=0;
		for(int b=1;b<=n;b++){
			if(people>=a[b]){
				people++;
			}
			else if(s[1]=='0'){
				people++;
			}
			for(int c=1;c<=n;c++){
				if(c==b){
					continue;
				}
				if(people>=a[c]){
					people++;
				}
				else if(s[2]=='0'){
					people++;
				}
				for(int d=1;d<=n;d++){
					if(d==c){
						continue;
					}
					if(people>=a[d]){
						people++;
					}
					else if(s[3]=='0'){
						people++;
					}
					for(int e=1;e<=n;e++){
						if(e==d){
							continue;
						}
						if(people>=a[e]){
							people++;
						}
						else if(s[4]=='0'){
							people++;
						}
						for(int f=1;f<=n;f++){
							if(f==e){
								continue;
							}
							if(people>=a[f]){
								people++;
							}
							else if(s[5]=='0'){
								people++;
							}
							for(int g=1;g<=n;g++){
								if(g==f){
									continue;
								}
								if(people>=a[g]){
									people++;
								}
								else if(s[6]=='0'){
									people++;
								}
								for(int h=1;h<=n;h++){
									if(people>=a[h]){
										people++;
									}
									else if(s[7]=='0'){
										people++;
									}
									for(int i=1;i<=n;i++){
										if(people>=a[i]){
											people++;
										}
										else if(s[8]=='0'){
											people++;
										}
										for(int j=1;j<=n;j++){
											if(people>=a[j]){
												people++;
											}
											else if(s[9]=='0'){
												people++;
											}
											for(int k=1;k<=n;k++){
												if(people>=a[j]){
													people++;
												}
												else if(s[10]=='0'){
													people++;
												}
												if(b!=c&&b!=d&&b!=e&&b!=f&&b!=g&&b!=h&&b!=i&&b!=j&&b!=k&&c!=d&&c!=e&&c!=f&&c!=g&&c!=h&&c!=i&&c!=j&&c!=k&&d!=e&&d!=f&&d!=g&&d!=h&&d!=i&&d!=j&&d!=k&&e!=f&&e!=g&&e!=h&&e!=i&&e!=j&&e!=k&&f!=g&&f!=h&&f!=i&&f!=j&&f!=k&&g!=h&&g!=i&&g!=j&&g!=k&&h!=i&&h!=j&&h!=k&&i!=j&&i!=k&&j!=k){
													if(10-people>=m){
														ans++;
													}
												}
												people=0;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}
}
