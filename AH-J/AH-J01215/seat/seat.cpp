#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
//#define int ll
const int mod=1e9+7;
const int N=1e5+50;
#define endl '\n'
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n,m;
int a[N]={};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	IO;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1];
	int pos=0;
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			pos=i;
			break;
		}
	}
	int tmp1=pos%(n*2);
	if(tmp1==0){
		cout<<pos/(n*2)*2<<" "<<1<<endl;
		return 0;
	}
	if(tmp1<=n){
		cout<<pos/(n*2)*2+1<<" "<<tmp1;
	}else{
		cout<<pos/(n*2)*2+2<<" "<<n-(tmp1-n)+1;
	}
	return 0;
}
