#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sear.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,kkk=0,sc=0,chen=0,zhe=0;
	int a[110];
	scanf("%d%d",&n,&m);//I do not want TLEEEE
	const int CSPJ=n*m;
	for(int i=1;i<=CSPJ;i++){
		cin>>a[i];
	}
	kkk=a[1];
	sort(a+1,a+CSPJ+1);//zro SORT orz
	for(int i=CSPJ;i>=1;i--){//i--!!!!
		//cout<<a[i]<<endl<<CSPJ<<endl;
		if(a[i]==kkk){
			//cout<<endl<<i<<endl;
			sc=CSPJ-i+1;//I know this is too silly but I can not think about any other finding
			break;
		}
	}
	for(int i=1;i<=CSPJ;i++){
		if(sc/n<i||(sc/n==i&&sc%n==0)){
			chen=i;
			break;
		}
	}
	if(chen%2!=0){
		if(sc%n!=0){
			zhe=sc%n;
		}else{
			zhe=n;
		}
	}else{
		if(sc%n!=0){
			//cout<<n<<endl<<sc<<endl<<sc%n<<endl;
			zhe=n-(sc%n)+1;
		}else{
			zhe=1;
		}
	}
	cout<<chen<<" "<<zhe;//if there is "_" that I will happy[doge]
	return 0;
}
//BY HB-J00277
