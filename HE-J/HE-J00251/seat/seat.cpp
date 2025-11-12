#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15];
int main(){
	freopen("seat","r",stdin);
	freopen("seat","w",stdout);
	cin>>n>>m;
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[j][i];
			if(a[1][1]<=a[j][i]){
				ans++;
			}
		}
	}
	int q=1;
	int p=1;
    while(ans>0){
    	if(q<n&&p%2!=0&&p<=m){
    		q++;
    		ans--;
		}else if(q==n&&p%2!=0&&p<m){
			p++;
			ans--;
		}else if(q<=n&&q!=1&&p%2==0&&p<=m){
			q--; 
			ans--;
		}else if(q==1&&p%2==0&&p<m){
			p++;
			ans--; 
		}
	}
    cout<<p<<" "<<q;
	return 0;
}
