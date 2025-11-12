#include<bits/stdc++.h> 
using namespace std;
int a[1000017];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int q=0,w=0,e;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
				q++;
	}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
		if(q==1){
    		cout<<s[i];
    		break;
		}else{
			for(int j=0;j<q;j++){
			s[i]=a[j];
		}
		}
	}else{
		continue;
	}
	}
	sort(a,a+q);
    for(int j=q-1;j>=0;j--){
		w=w+a[j];
		e=w*10;
		}if(e>0){
		cout<<e;
		}
	


	return 0;
}
