#include<bits/stdc++.h>
using namespace std;
int arr[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int m=a.size();
    for(int i=0;i<m;i++){
		int temp=int(a[i])-48;
		if(temp>=0&&temp<=9){
            arr[temp]+=1;
		}
	}
    for(int i=9;i>=0;i--){
        for(int j=arr[i];j>0;j--){
            cout<<i;
        }
    }

    return 0;
}
