#include <bits/stdc++.h>
using namespace std;

int main (){
    freopen("number.in","r",stdin);
    freopen("number.ans","w",stdout);
    string a;
    cin>>a;
    char q[a.size()+5];
    int sum=0,w=a.size();
    for(int i=0;i<w;i++){
        if(a[i]>='0'&&a[i]<='9'){
            q[sum]=a[i];
            sum++;
        }
    }
    for(int i=0;i<sum-1;i++){
		for(int j=0;j<sum-i-1;j++){
			if(q[j]<q[j+1]){
				swap(q[j],q[j+1]);
			}
		}
	}		
    for(int i=0;i<sum;i++){
        cout<<q[i];
    }
    return 0;
}

