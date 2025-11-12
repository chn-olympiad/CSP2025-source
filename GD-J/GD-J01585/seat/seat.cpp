#include<bits/stdc++.h>
using namespace std;
int n,m,sc[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int mi,pl;
	for(int i=1;i<=n*m;i++){
		cin>>sc[i];
		if(i==1)mi=sc[i];
	}
	sort(sc+1,sc+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(sc[i]==mi){
			pl=i;
			break;
		}
	}
	if(pl%n==0){
		int lie=pl/n;
		if(lie%2==1){
			cout<<lie<<" "<<n;
		}
		else{
			cout<<lie<<" "<<1;
		} 
	}
	else{
		int lie=pl/n+1,res=n*lie-pl;
		if(lie%2==1){
			cout<<lie<<" "<<pl%n;
		}
		else{
			cout<<lie<<" "<<n-(pl%n)+1;
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
