#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],z,b;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	b=n;
	for(int i=0;i<n;i++){
		if(s[i]==0){
			b=1;
			break;
		}
	}
	if(m==1){
		sort(a+1,a+n+1);
		int y=0;
		for(int i=0;i<n;i++){
			if(s[i]==1&&a[n]!=0)a[n]=0;
			else if(a[n]==0){
				int p=0;
				while(++p<=n){
					if(a[p]!=0){
						cout<<0;
						fclose(stdin);
						fclose(stdout);
						return 0;
					}
				}
			}else{
				while(++z<a[++y]){
					a[y]=0;
				}
			}
		}
		cout<<1;
	}else if(m==n){
		if(b!=0)cout<<0;
		else {
			int te=1;
			for(int i=1;i<=n;i++){
				te*=n;
				te%=998244353;
			}
			cout<<te;
		}
	}else if(b==0){
		if(m!=n)cout<<0;
		else {
			int te=1;
			for(int i=1;i<=n;i++){
				te*=n;
				te%=998244353;
			}
			cout<<te;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//16:32 I'm begining sleep
//daji I don't know!!!! qwq
//cout<<"goodbye csp-s";
//songs are very good
/*        ----
          |  |
     -----   -------
     -----   -------
         |   |
-------------------------
|                       |
|                       |
|       11:45:14        |
|                       |
|  ccf csp-s kill me    |
|         qwq           |
|        so nan         |
|                       |
|   csp-j I love you    |
|                       |
|   #               #   |
|                       |
|      *********        |
|                       |
-------------------------
16:49
*/
