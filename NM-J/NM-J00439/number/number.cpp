#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int ji=1;
	priority_queue<int> sum;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			sum.push(a[i]-'0');
			ji++;
		}
	}

	for(int i=1;i<ji;i++){
		cout<<sum.top();
		sum.pop();
	}


	return 0;
}
