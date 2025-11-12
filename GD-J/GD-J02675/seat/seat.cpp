#include<bits/stdc++.h>
const int N=144;
int a[N];
void solve(){
    int n,m;
    std::cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	std::cin>>a[i];
	}
	int k=a[1],ki;
	std::sort(a+1,a+n*m+1,std::greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			ki=i;
			break;
		}
	}
	if(ki%n==0){
		std::cout<<ki/n<<" "<<n;
		return ; 
	}
	else{
		if((ki/n)%2==0){
			std::cout<<ki/n+1<<" "<<k%n;
			return ; 
		}
		else{
			std::cout<<ki/n+1<<" "<<n-(ki%n)+1;
			return ;
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
