#include<bits/stdc++.h>
using namespace std;
int s,a[10086],c=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=1;i<=10086;i++){
        a[i]=s%10;
        s/=10;
        c++;
        if(s==0){
        	a[i+1]=0;
		}
		cout<<a[i]<<endl;
        if(s<=0){
        	break;
		}
	}
    sort(a+1,a+c+1);
    for(int i=c;i>=1;i--){
        	cout<<a[i];
	}
	return 0;
}
