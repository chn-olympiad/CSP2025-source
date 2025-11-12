#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string a;
int b[N];



int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	a=' '+a;
	for(int i=1;i<=a.size();i++){
		if(a[i]=='0')b[0]++;
		else if(a[i]=='1')b[1]++;	
		else if(a[i]=='2')b[2]++;	
		else if(a[i]=='3')b[3]++;	
		else if(a[i]=='4')b[4]++;	
		else if(a[i]=='5')b[5]++;	
		else if(a[i]=='6')b[6]++;	
		else if(a[i]=='7')b[7]++;	
		else if(a[i]=='8')b[8]++;	
		else if(a[i]=='9')b[9]++;	
	}
	
	for(int i=9;i>=0;i--){
		while(b[i]--){
			cout<<i;
		}
	}
	
	return 0;
}
