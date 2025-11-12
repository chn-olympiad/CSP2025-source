#include<bits/stdc++.h>
using namespace std;
char s[1000006]={'-'};
int num[1000006]={9},n,you=0,mi=0,l1=0,l2=0,l3=0,l4=0;
void pan(int i){
	if(i=='1') { num[you]=1;you++;
	}else if(i=='2') { num[you]=2;you++;
	}else if(i=='3') {num[you]=3;you++;
	}else if(i=='4') { num[you]=4;you++;
	}else if(i=='5') {num[you]=5;you++;
	}else if(i=='6') {num[you]=6;you++;
	}else if(i=='7') {num[you]=7;you++;
	}else if(i=='8') {num[you]=8;you++;
	}else if(i=='9') {num[you]=9;you++;
	}else if(i=='0') {num[you]=0;you++;
	} 
}
void pai(){
	int a=0;
	for(int i=0;i<=you-1;i++){
		for(int j=0;j<=you-1;j++){
			if(num[j]<num[j+1]){
				a=num[j];
				num[j]=num[j+1];
				num[j+1]=a;
			}
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s[1]=='-'){
		if(s[0]=='1') {cout<<s[0];return 0;
		}else if(s[0]=='2') {cout<<s[0];return 0;
			}else if(s[0]=='3') {cout<<s[0];return 0;
		}else if(s[0]=='4') {cout<<s[0];return 0;	
		}else if(s[0]=='5') {cout<<s[0];return 0;
			}else if(s[0]=='6') {cout<<s[0];return 0;
		}else if(s[0]=='7') {cout<<s[0];return 0;
		}else if(s[0]=='8') {cout<<s[0];return 0;	
			}else if(s[0]=='9') {cout<<s[0];return 0;
		}else if(s[0]=='0') {cout<<s[0];return 0;
		} 
	}
	
	while(s[n]!='m'){
		pan(s[n]);
		n++;
	}
	pai();
	for(int i=0;i<=you-1;i++){
		if(num[i]==1){
			if(l1==0){l1=1;continue;
			}
		}if(num[i]==2){
			if(l2==0){l2=1;continue;
			}
		}if(num[i]==3){
			if(l3==0){l3=1;continue;
			}
		}if(num[i]==4){
			if(l4==0){l4=1;continue;
			}
		}
		cout<<num[i];
	}
	
	return 0;
}
 
