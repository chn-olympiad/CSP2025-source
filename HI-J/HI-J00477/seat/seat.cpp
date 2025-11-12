#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int scr[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,prs;
	cin>>a>>b;
	for(int i=0;i<a*b;i++){
		cin>>scr[i];
	}
	prs=scr[0];
	sort(scr,scr+a*b);
	for(int i=a*b-1;i>=0;i--){
		if(scr[i]==prs){
			int k=a*b-i;
			cout<<ceil(k/(a*1.0));
			if(int(ceil(k/(a*1.0)))%2==0){
				cout<<' '<<a-((k%a)==0?a:k%a)+1;
			}	
			else cout<<' '<<((k%a)==0?a:k%a);		
		}
	}
	return 0;
}	
