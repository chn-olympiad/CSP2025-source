#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number1.in","r",stdin);
	freopen("number1.out","w",stdout);
	string n;
	cin>>n;
    int a[10]={0};
    for(int i=0;i<n.length();i++){
        int s=n[i]-'0';
        if(s>=0&&s<=9){
            a[s]++;
        }
    }
    for(int i=9;i>=0;i--)while(a[i]--)cout<<i;
	return 0;
}
