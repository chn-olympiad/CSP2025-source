#include<bits/stdc++.h>
using namespace std;
long long a[20];
string q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>q;
	long long lon=q.size();
	for(long long i=0;i<lon;i++){
		if(q[i]=='0'){
			a[0]+=1;
		}else if(q[i]=='1'){
			a[1]+=1;
		}else if(q[i]=='2'){
			a[2]+=1;
		}else if(q[i]=='3'){
			a[3]+=1;
		}else if(q[i]=='4'){
			a[4]+=1;
		}else if(q[i]=='5'){
			a[5]+=1;
		}else if(q[i]=='6'){
			a[6]+=1;
		}else if(q[i]=='7'){
			a[7]+=1;
		}else if(q[i]=='8'){
			a[8]+=1;
		}else if(q[i]=='9'){
			a[9]+=1;
		}
	}
	for(int i=9;i>=0;i--){
		for(long long j=a[i];j>0;j--){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
