#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;cin>>a;
	long long arr[1000000]={ };long long n=0,h;
	for(int i=0;i<a.length();i++){
		if(a[i]%1==0 and a[i]>=48 and a[i]<=57){
			arr[n]=(a[i]-'0');
			n++;
			}
		}
	for(int i=0;i<n;i++){
		for(int q=i+1;q<n;q++){
			if(arr[i]<arr[q]){
				h=arr[i],arr[i]=arr[q],arr[q]=h;
				}
			}
		}
	for(int i=0;i<n;i++){
		cout<<arr[i];
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
