#include <bits/stdc++.h>

using namespace std;

int t[10];
string a;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	//char b=a.length;
	//cout<<'a'-0<<" "<<'s'-0<<" ";//length
	for(int i=0;i<1000005;i++){
		//cout<<a[i]<<" "<<a[i]-0<<endl; 
		if(a[i]=='0'){
			t[0]++;
		}else if(a[i]=='1'){
			t[1]++;
		}else if(a[i]=='2'){
			t[2]++;
		}else if(a[i]=='3'){
			t[3]++;
		}else if(a[i]=='4'){
			t[4]++;
		}else if(a[i]=='5'){
			t[5]++;
		}else if(a[i]=='6'){
			t[6]++;
		}else if(a[i]=='7'){
			t[7]++;
		}else if(a[i]=='8'){
			t[8]++;
		}else if(a[i]=='9'){
			t[9]++;
		}else{
			if(a[i]-0==0) break;
		}
	}
	for(int i=0;i<10;i++){
		while(t[9-i]--){
			cout<<9-i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
