#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int w;
	string num[10086];
	int q=0;
	cin>>a;
	w=a.size();
	for (int i=0;i < w;i++){
		if(int(a[i])>=48 and int(a[i])<=57){
			num[q]=a[i];
			q++;
		}
	}
	for (long long j=0;j < q;j++){
		for (long long i=0;i <j ;i++){
			if (num[i]<num[i+1]){
				swap(num[i],num[i+1]);
			}
		}
	}
	for (long long i=0;i < q;i++){
		cout<<num[i];
	}
}
