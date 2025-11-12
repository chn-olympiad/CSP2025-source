#include <bits/stdc++.h> 
using namespace std;
int a[105],s[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l,h,c,xu;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		s[n*m-i+1]=a[i];
	}
	for(int i=1;i<=n*m;i++){
		if(s[i]==r){
			xu=i;
			break;
		}
	}
	l=xu/n;
	c=xu%n;
	if(c!=0){
		l++;
	}else{
		if(l%2==0){
			cout<<l<<" "<<1<<endl;
			return 0;
		}else{
			cout<<l<<" "<<n<<endl;
			return 0;
		}
	}
	if(l%2==0){
		h=n-xu+n*(l-1)+1;
		cout<<l<<" "<<h<<endl;
	}else{
		h=xu-n*(l-1);
		cout<<l<<" "<<h<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
