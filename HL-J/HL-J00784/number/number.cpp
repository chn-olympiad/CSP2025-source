#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string sum;
	string m;
	string n;
	cin >> m;
	for(int i=0;i<=m.size();i++){ 
		if(m[i]>='0'){
			if(m[i]<='9'){
				n+=m[i];
			}	
		}	
	}
	for(int s1=0;s1<=n.size();s1++){
		if(n[s1]=='9'){
			sum+=n[s1];
		}
	}
	for(int s2=0;s2<=n.size();s2++){
		if(n[s2]=='8'){
			sum+=n[s2];
		}
	}
	for(int s3=0;s3<=n.size();s3++){
		if(n[s3]=='7'){
			sum+=n[s3];
		}
	}
	for(int s4=0;s4<=n.size();s4++){
		if(n[s4]=='6'){
			sum+=n[s4];
		}
	}
	for(int s5=0;s5<=n.size();s5++){
		if(n[s5]=='5'){
			sum+=n[s5];
		}
	}
	for(int s6=0;s6<=n.size();s6++){
		if(n[s6]=='4'){
			sum+=n[s6];
		}
	}
	for(int s7=0;s7<=n.size();s7++){
		if(n[s7]=='3'){
			sum+=n[s7];
		}
	}
	for(int s8=0;s8<=n.size();s8++){
		if(n[s8]=='2'){
			sum+=n[s8];
		}
	}
	for(int s9=0;s9<=n.size();s9++){
		if(n[s9]=='1'){
			sum+=n[s9];
		}
	}
	for(int s=0;s<=n.size();s++){
		if(n[s]=='0'){
			sum+=n[s];
		}
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}