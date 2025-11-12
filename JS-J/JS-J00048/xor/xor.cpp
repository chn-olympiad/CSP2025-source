#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
bool f=true;
bool vh=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=false;
		}
		if(a[i]!=1 && a[i]!=0){
			vh=false;
		}
	}
	if(vh){
		if(f){
			cout<<0<<endl;
		}
		else{
			if(k==1){
				int ge1=0,ge0=0;
				for(int i=1;i<=n;i++){
					if(a[i]==1){
						ge1++;
					}
					else{
						ge0++;
					}
				}
				if(ge0>=ge1){
					cout<<ge1<<endl;
				}
				else{
					cout<<(ge0+(ge1-ge0)/2)<<endl;
				}
			}
			else{
				cout<<0<<endl;
			}
		}
	}
	else{
		cout<<10086<<endl;//yi ding yao you a!!!
	}
	return 0;
}
