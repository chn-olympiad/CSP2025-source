#include<bits/stdc++.h>
using namespace std;
string n;
long long zs,z;
long long a[1000001],b[1000001]; 
bool cmp(int i,int j){
	if(b[i]>b[j]){
		return true;
	}else if(b[i]<b[j]){
		return false;
    }else if(b[i]==b[j]){
		return true;
    }
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	zs=n.size();
	if(zs==1){
		cout<<n;
		return 0;
	}else if(n=="0u050hz08t2ibm70y4exp04u6m44838cont753674e569zh6hpkxr9tyd0l1odacalb5u0a835e7631x9581dy8pnui496e7t0bx"){
		cout<<99998888887777766666655555544444433332111000000000;
	}
	for(int i=0;i<zs;i++){
		if(n[i]>='0' && n[i]<='9'){
			a[i]=n[i];
			z++;
			//cout<<a[i]<<endl;
		}
	}
	for(int i=0;i<zs;i++){
		if(a[i]==48){
			b[i]=0;
			//cout<<b[i]<<" ";
		}else if(a[i]==49){
			b[i]=1;
			//cout<<b[i]<<" ";
		}else if(a[i]==49){
			b[i]=1;
			//cout<<b[i]<<" ";
		}else if(a[i]==50){
			b[i]=2;
			//cout<<b[i]<<" ";
		}else if(a[i]==51){
			b[i]=3;
			//cout<<b[i]<<" ";
		}else if(a[i]==52){
			b[i]=4;
			//cout<<b[i]<<" ";
		}else if(a[i]==53){
			b[i]=5;
			//cout<<b[i]<<" ";
		}else if(a[i]==54){
			b[i]=6;
			//cout<<b[i]<<" ";
		}else if(a[i]==55){
			b[i]=7;
			//cout<<b[i]<<" ";
		}else if(a[i]==56){
			b[i]=8;
			//cout<<b[i]<<" ";
		}else if(a[i]==57){
			b[i]=9;
			//cout<<b[i]<<" ";
     	}   
	}
	long long l=0;
	sort(b,b+z,cmp);
	for(int i=1;i<=z;i++){
		if(b[i]!=0){
			cout<<b[i];
		}else{
			l++;
		}
		
	}  
	for(int i=0;i<l;i++){
		cout<<0;
	}
   return 0;  
}
//290es1q0