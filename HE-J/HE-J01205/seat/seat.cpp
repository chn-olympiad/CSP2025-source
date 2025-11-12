#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],s[101][101],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	cnt=n*m+1;
	int a1=a[1];
	sort(a+1,a+n*m+1);
    for(int i=0;i<n;i++){
    	if(i%2==0){
    		for(int j=0;j<m;j++){
		        cnt--;
				s[j][i]=a[cnt];
		    }
		    continue;
		} 
		else{
			for(int j=n-1;j>=0;j--){
				cnt--;
				s[j][i]=a[cnt];
		    }
		    continue;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]==a1){
				if(n==m){
					cout<<j+1<<' '<<i+1;
				}
			    else{
			    	cout<<i+1<<' '<<j+1;
				}
				return 0;
			}
		}
	}
	return 0;
}
