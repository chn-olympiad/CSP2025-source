#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sc[100005];
	for(int i=1;i<=n*m;i++){
		cin>>sc[i];
	}
	int rc=sc[1];
	sort(sc+1,sc+n*m+1);
	int pai=1,z;
	for(int i=n*m;i>=1;i--){
		if(sc[i]==rc){
			break;
		}
		pai++;
	}
	//for(int i=1;i<=n*m;i++) cout<<sc[i]<<endl;
	//cout<<pai;
	if((pai/n+1)%2==0&&pai%n!=0){
		if((pai%n)!=0) cout<<pai/n+1<<" "<<n+1-pai%n;
	}else if((pai/n+1)%2==1&&pai%n!=0){
		if((pai%n+1)!=0) cout<<pai/n+1<<" "<<pai%n;
	}else if(pai%n==0&&(pai/n)%2==0){
		cout<<pai/n<<" "<<1;
	}else cout<<pai/n<<" "<<n;
	return 0;
}
