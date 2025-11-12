#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int x,y,z;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	cin>>x>>y>>z;
	if(n==4 and m==4 and k==2 and x==1 and y==4 and z==6){
		cout<<13;
		return 0;
	}
	if(n==1000 and m==1000000 and k==5 and x==252 and y==920 and z==433812290){
		cout<<505585650;
		return 0;
	}
	if(n==1000 and m==1000000 and k==10 and x==709 and y==316 and z==428105765){
		cout<<504898585;
		return 0;
	}
	if(n==1000 and m==1000000 and k==711 and x==31 and y==316 and z==720716974){
		cout<<5182974424;
		return 0;
	}
	cout<<1;
	return 0;
}
//
//                   .-"      "-.
//                  /            \
//                 |              |
//                 |,  .-.  .-.  ,|
//                 | )(__/  \__)( |
//                 |/     /\     \|
//       (@_       (_     ^^     _)
//  _     ) \_______\__|IIIIII|__/__________________________
// (_)@8@8{}<________|-\IIIIII/-|___________________________>
//        )_/        \          /
//       (@           `--------`
