#include <iostream>
#include <string>
using namespace std;
int n,m,a[100005],cnt=0,p=0,sum=0;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < n;i++){
		cnt=0,sum=0;
		for(int j = 0;j < n;j++){
			if(s[i]=='0'){
				sum++;
			}
			if(s[i] != '0' && sum <= a[i]){
				cnt++;
			}
		}
		cout << sum << " " << cnt << "\n";
		if(cnt != 0 && cnt>= m){
			p++;
		}
	}
	cout << p;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
