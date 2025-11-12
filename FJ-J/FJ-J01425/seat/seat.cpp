#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,s;
	cin>>a>>s;
	int d[a*s],q;
	for(int i=0;i<a*s;i++){
		cin>>d[i];
	}
	q=d[0];
	sort(d,d+a*s);
	for(int i=0;i<a*s;i++){
		if(d[i]==q){
			if(((a*s-i-1)/a+1)%2==0){
				cout<<(a*s-i-1)/a+1<<' '<<s-((a*s-i)-((a*s-i-1)/a+1)*s)-1;
				break;
			}
			cout<<(a*s-i-1)/a+1<<' '<<(a*s-i)-((a*s-i-1)/a)*s;
			break;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
