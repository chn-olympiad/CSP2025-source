#include<bits/stdc++.h>
using namespace std;
int a[500500];
void delete1(int begin,int end){
	for(int i=begin;i<=end;i++)a[i]=-1;
}

int find(int begin){
	for(int i=begin;;i++){
		if(a[i]!=-1){
			return i;
			break;
		}
	}
	return -1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,sum=2;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			a[i]=-1;
		}
	}
	if(k==0){
		cout<<1;
		return 0;
	}
	for(int i=0;i<n;i++){
		int x=a[find(i)],w=find(i),f=1;
		for(int j=i+1;j<n;j++){
			x^=a[j];
			f++;
			if(x==k){
				ans++;
				delete1(w,j);
				cout<<99999999<<endl;
				x=0;
				f=0;
			}
			else if(f==i+2){
				x^=a[j-f+1];
				f--;
			}
		}
	} 
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
	cout<<endl<<ans;
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
//#Shang4Shan3Ruo6Shui4
