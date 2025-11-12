#include<iostream>
#include<algorithm>
using namespace std;
string a,b;
int cs[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int js=0,c=0;
	for(int i=0;i<a.size();i++){
		if(a[i]-'0'>=0&&a[i]-'0'<=9){
			cs[js]=a[i]-'0';
			js++;
		}
	} 
	sort(cs,cs+js);
	for(int i=js-1;i>=0;i--){
		b[c]=cs[i]+'0';
		c++;
	}
	for(int i=0;i<c;i++){
		cout<<b[i];
	}
	return 0;
} 
