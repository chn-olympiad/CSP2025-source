#include <bits/stdc++.h>
using namespace std;
long long n,m;//n=hang m=lie
long long templ;
long long sc;
long long pos=1;
long long lieshu,hangshu;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >>n >>m;
	cin >>sc;
	for(int i=1;i<(n*m);i++){
		cin >>templ;
		if(templ>sc)pos++;
	}//cishi pos shi dijige
	
	lieshu=pos/n;
	if(pos%n!=0)lieshu+=1;
	if(lieshu%2==1){//jishu
		hangshu=pos-(lieshu-1)*n;
	}else{
		hangshu=n-(pos-(lieshu-1)*n)+1;
	}
	//cout <<"pos" <<pos <<" " ; 
	cout <<lieshu <<" " <<hangshu;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
