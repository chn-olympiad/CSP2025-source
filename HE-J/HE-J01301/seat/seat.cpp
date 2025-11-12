#include<bits/stdc++.h>
using namespace std;
int mark[10000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	const int len=n*m;
	for(int i=0;i<len;i++){
		cin>>mark[i];
	}const int Lr=mark[0];
	sort(mark,mark+len,[](int x,int y){return x>y;});
	int flag=0;
	for(int i=len-1;i>=0;i--){
		if(mark[i]==Lr){
			flag=i;
			break;
		}
	}
	const int retL=(flag/n)+1;
	cout<<retL<<' '<<((retL%2==0)?(n-(flag-(retL-1)*n)):(1+(flag-(retL-1)*n)));
	
	return 0;
}
