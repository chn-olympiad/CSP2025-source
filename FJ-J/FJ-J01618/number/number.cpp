#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000010],top = 1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i = 0;i < a.size();i++){
		if(int(a[i]) - 48 >= 0 && int(a[i]) - 48 <= 9){
			b[top] = int(a[i]) - 48;
			top++;
		}
	}
	sort(b + 1,b + top);
	for(int i = top - 1;i >= 1;i--){
		cout<<b[i];
	}
	return 0;
}

