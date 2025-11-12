#include <bits/stdc++.h>
using namespace std;
long long n,k;
long long arr[500005];
long long cnt=0;
long long templ;
bool flag=0;
int main(){
	freopen("xor1.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n >>k;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		arr[i]=arr[i]^k;
		if (arr[i]==0)cnt++;
	}
	cout <<cnt;
	/*for(int i=1;i<n;){
		flag=0;
		if(arr[i]==k){
			cnt++;
			i++;
			flag=1;
			continue;
		}
		templ=arr[i];
		for(int j=i+1;j<=n;j++){
			templ=templ^arr[j];
			//cout <<endl <<i << "to" <<j <<";";
			if(templ==k){
				cnt++;
				//cout <<"yes";
				//cout <<endl <<i << "to" <<j <<";";
				i=j+1;
				flag=1;
				break;
			}
		}
		if(flag==0)i++;
	}*/
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
