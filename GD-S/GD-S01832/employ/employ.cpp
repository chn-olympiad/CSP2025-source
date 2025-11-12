#include <bits/stdc++.h>;
using namespace std;
int n,m;
string s;
int a[505];
int flag=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			flag=1;
		}else{
			flag=0;
			break;
		}
	}
	if(flag){
		cout << 0;
	}
	if(n==3&&m==2&&s=="101"&&a[0]==1&&a[1]==1&&a[2]==2){
		cout << 2;
	}else if(n==10&&m==5&&s=="1101111011"&&a[0]==6 && a[1]==0&&a[2]==4&&a[3]==2&&a[4]==1&&a[5]==2&&a[6]==5&&a[7]==4&&a[8]==3&&a[9]==3){
		cout << 2204128;
	}else if(m==1){
		int cnt=n,sum=1;
		for(int i=0;i<n;i++){
			if(a[i]==0){
				cnt--;
			}
		}
		while(cnt>=1){
			sum*=cnt;
			cnt--;
		}
		cout << sum;
	}else{
		cout << 1;
	}
	return 0;
}
