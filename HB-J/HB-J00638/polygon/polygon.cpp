# include <bits/stdc++.h>
using namespace std;
long long l[500050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,suml=0,max=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		suml+=l[i];
		if(max<l[i]) max=l[i];
	}
	if(suml>max*2) sum++;
	cout<<sum<<endl;
	return 0;
}

