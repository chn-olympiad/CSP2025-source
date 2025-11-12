#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,gra[105],rg;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>gra[i];
		}
	rg=gra[1];
	sort(gra+1,gra+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(gra[i]==rg){
			rg=n*m-i+1;
			break;
			}
		}
	if(rg%n==0){
		if(rg/n%2==0){
			cout<<rg/n<<" "<<1;
			}
		else{
			cout<<rg/n<<" "<<n; 
			}
		}
	else{
		if(((rg/n)+1)%2==0){
			cout<<rg/n+1<<" "<<n+1-rg%n;
			}
		else{
			cout<<rg/n+1<<" "<<rg%n;
			}
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
