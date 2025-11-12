#include<bits/stdc++.h>
using namespace std;
int s[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
    for(int i=0;i<n*m;i++){
    	cin>>s[i];
	}
	int ans=0,b=n*m;
	for(int i=1;i<n*m;i++){
		if(s[i]<s[0])ans++;
	}
	int c=b-ans;
	if(c<=n){
		cout<<1<<' '<<c;
		return 0;
	}
	if(c%n==0){
		cout<<c/n<<' ';
		if((c/n)%2==0){
			cout<<1;
		}else{
			cout<<n;
		}
		return 0;
	}
	if((c/n+1)%2==0){
		cout<<c/n+1<<' '<<n-(c%n)+1;
	}else{
		cout<<c/n+1<<' '<<c%n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
