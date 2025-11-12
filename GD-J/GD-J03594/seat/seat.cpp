#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],rp,st,tp,hang,lie;
int s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=0;i<s;i++) cin>>a[i];
	rp=a[1];
	sort(a,a+s);
	for(int i=0;i<s;i++){
		if(a[i]==rp){
			st=i;
		}
	}
	tp=s-st+1;
	lie=((tp+n-1)/n);
	if(lie%2==1){
		hang=(tp-((lie-1)*n));
	}
	else{
		hang=(tp-((lie-1)*n));
		hang=n-hang+1;
	}
	cout<<lie<<" "<<hang;
	return 0;
} 
