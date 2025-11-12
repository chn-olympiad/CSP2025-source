#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],y,q=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		y=s[i]-48;
		if(y>=0&&y<=9){
			q++;
			a[q]=y;
		}
	}
	sort(a+1,a+q+1);
	for(int i=q;i>0;i--) cout<<a[i];
	return 0; 
}
