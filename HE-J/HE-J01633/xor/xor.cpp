#include<bits/stdc++.h>
using namespace std;
int m,n,ans=0;
int s[20][20],num[20][20];
int a[150],b[150]= {0};
//long long testt[10][10]={}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	int num=a[1];
	sort(a+1,a+1+(n*m));
	/*
	for(int i=n*m;i>=1;i--)
	{
		cout<<a[i]<<endl;
	}
	*/
	for(int i=n*m; i>=1; i--) {
		if(num==a[i]) {
			ans=(n*m)+1-i;
			break;
		}
	}
	/*
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {

		}
	}
	*/
	/*
	for(int k=1; k<=n*m; k++) {
		for(int j=1; j<=m; j++) {
			if(j%2==0) {
				for(int i=n+cnt; i>=1+cnt; i--) {
					s[j][i]=i;
					cout<<s[j][i]<<" "<<i<<" "<<j<<endl;
					cnt=n+cnt;
					break;
				}
			} else {
				for(int i=1+cnt; i<=n+cnt; i++) {
					s[j][i]=i;
					cout<<s[j][i]<<" "<<i<<" "<<j<<endl;
					cnt=n+cnt;
					break;
				}
			}
		}
	}
	*/
	
	//×îÖÕ°æ 
	/*int cnt=0;
	for(int j=1; j<=m; j++) {
		if(j%2!=0) {
			for(int i=1+cnt; i<=n+cnt; i++) {
				if(i<=n*m) {
					s[j][i]=i;
					cnt+=n;
					//cout<<i<<"ji"<<endl;
					continue;
				} else {
					break;
				}
			}
		} else {
			for(int i=n+cnt; i>=1+cnt; i++) {
				if(i<=n*m) {
					s[j][i]=i;
					cnt+=n;
					//cout<<i<<"ou"<<endl;
					continue;
				} else {
					break;
				}
			}
		}
	}*/
	//×îÖÕ°æ 
	/*
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	for(int j=1; j<=m; j++) {
		for(int i=1; i<=n; i++) {
			if(ans==s[i][j])
				cout<<i<<" "<<j;
			break;
		}
	}
	return 0;
}
/*
2 2
99 100 97 98
*/




















/*
#include<bits/stdc++.h>
using namespace std;
int m,n,ans=0;
int s[20][20],num[20][20];
int a[150],b[150]= {0};
//long long testt[10][10]={}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	int num=a[1];
	sort(a+1,a+1+(n*m));
	/*
	for(int i=n*m;i>=1;i--)
	{
		cout<<a[i]<<endl;
	}
	for(int i=n*m; i>=1; i--) {
		if(num==a[i]) {
			ans=(n*m)+1-i;
			break;
		}
	}
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {

		}
	}
	for(int k=1; k<=n*m; k++) {
		for(int j=1; j<=m; j++) {
			if(j%2==0) {
				for(int i=n+cnt; i>=1+cnt; i--) {
					s[j][i]=i;
					cout<<s[j][i]<<" "<<i<<" "<<j<<endl;
					cnt=n+cnt;
					break;
				}
			} else {
				for(int i=1+cnt; i<=n+cnt; i++) {
					s[j][i]=i;
					cout<<s[j][i]<<" "<<i<<" "<<j<<endl;
					cnt=n+cnt;
					break;
				}
			}
		}
	}
	*/
	
	//×îÖÕ°æ 
	/*int cnt=0;
	for(int j=1; j<=m; j++) {
		if(j%2!=0) {
			for(int i=1+cnt; i<=n+cnt; i++) {
				if(i<=n*m) {
					s[j][i]=i;
					cnt+=n;
					//cout<<i<<"ji"<<endl;
					continue;
				} else {
					break;
				}
			}
		} else {
			for(int i=n+cnt; i>=1+cnt; i++) {
				if(i<=n*m) {
					s[j][i]=i;
					cnt+=n;
					//cout<<i<<"ou"<<endl;
					continue;
				} else {
					break;
				}
			}
		}
	}*/
	//×îÖÕ°æ 
	/*
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int j=1; j<=m; j++) {
		for(int i=1; i<=n; i++) {
			if(ans==s[i][j])
				cout<<i<<" "<<j;
			break;
		}
	}
	return 0;
}

2 2
99 100 97 98
*/
