#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int z=n*m;
	int s[z+1]={};
	for(int i=0;i<z;i++){
		cin>>s[i];
	}
	int r=s[0],cnt=0;
	sort(s,s+z,cmp);
	for(int i=0;i<z;i++){
		if(s[i]==r){
			cnt=i+1;
			break;
		}
	} 
	if(cnt%n!=0){
		if((cnt/n+1)%2==0) cout<<cnt/n+1<<" "<<n-(cnt%n)+1;
		else cout<<cnt/n+1<<" "<<cnt%n;
	}
	else{
		if((cnt/n)%2==0) cout<<cnt/n<<" "<<1;
		else cout<<cnt/n<<" "<<n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
