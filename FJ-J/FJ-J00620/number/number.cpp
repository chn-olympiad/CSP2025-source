#include<bits/stdc++.h>
using namespace std;
long long q[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int len=a.size();
    for(int i=0;i<len;i++){
    	if(a[i]>='0'&&a[i]<='9'){
    		q[a[i]-'0']++;
	    }
	}
	int f=0;
	for(int i=1;i<=9;i++){
		if(q[i]!=0){
			f=1;
		}
	}
	if(f==1){
		for(int i=9;i>=0;i--){
			for(int j=q[i];j>0;j--){
				cout<<i;
			}
		}
	}else{
		cout<<0;
	}
	return 0;
}
