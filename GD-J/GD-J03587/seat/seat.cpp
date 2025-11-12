#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	string a[110];
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}	
	string s=a[0];
	if(s=="100"){
		cout<<"1 1";
		return 0;
		}
	for(int i=0;i<n*m;i++){
		if(a[i]=="100"){
			a[i]="999";
		}
	}	
	for(int i=0;i<n*m;i++){
		for(int j=i+1;j<n*m;j++){
		if(a[i]<a[j]){
			swap(a[i],a[j]);
		}
		}
	}	
	int z=1;
	for(int i=0;i<n*m;i++){
		if(a[i]==s)
		break;
		z++;
	}
	cout<<z<<endl;
	if(z%n==0&&z/n%2==0){
		cout<<z/n<<" "<<"1";
		return 0;
	}
	else if(((z/n)+1)%2==0)
	{
		cout<<z/n+1<<" "<<z-(z-((z/n)*n));
		}
		else{
			
	if(z%n==0){
		cout<<z/n<<" "<<n;
	}
	else{
		cout<<z/n+1<<" "<<z-z/n*n;
	}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
