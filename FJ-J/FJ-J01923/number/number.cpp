#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string n;
    cin>>n;
    int b=n.size();
    int a[b+5];
    int s=0;
    for(int i=0;i<b;i++){
    	if(n[i]=='0'||n[i]=='1'||n[i]=='2'||n[i]=='3'||n[i]=='4'||n[i]=='5'||n[i]=='6'||n[i]=='7'||n[i]=='8'||n[i]=='9'){
    		a[s]=n[i]-48;s++;
		}
	}
	sort(a,a+s);
	for(int i=s-1;i>=0;i--){
		cout<<a[i];
	}	
	return 0;
}

