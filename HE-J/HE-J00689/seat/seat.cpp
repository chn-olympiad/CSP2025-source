#include<bits/stdc++.h>
using namespace std;
int a,n,m,q1,q2,q3,q4,q5;
int s1,s[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	q5 = n*m;
	for(int i=0;i<q5;i++){
		cin>>s[i];
	}
	q1 = s[0];
	for(int i=1;i<=q5;i++){
		if(s[i]>q1){
			q2++;
		}
	}
	q3 = (q2+1)%n;
	q4 = q2/n+1;
	if(q4%2 != 0){
		if(q3 == 0){
			if(q4 == 0){
				cout<<1<<" "<<n;
				return 0;
			}
			cout<<q4<<" "<<n;
			return 0;
		}
		if(4 == 0){
			cout<<1<<" "<<q3;
			return 0;
		}
		else{
			cout<<q4<<" "<<q3;
			return 0;
		}
	}
	if(q4%2 == 0){
		if(q3 == 0){
			if(q4 == 0){
				cout<<1<<" "<<n;
				return 0;
			}
			cout<<q4<<" "<<1;
			return 0;
		}
		if(q4 == 0){
			cout<<1<<" "<<q3;
		}
		else{
			cout<<q4<<" "<<n-q3+1;
		}
	}
	return 0;
}
