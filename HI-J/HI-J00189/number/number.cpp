in<sit.>
main
{

int a,s[1001]; 
for(int i=1;i<=1000;i++){
	cin>>s[i];
	if(s[i]==0){
		a=i;
		break
	}
}


int q;
for(int i=1;i<=a;i++){
	
	
	for(int o=1;o<=a;o++){
		if(s[o]<s[o+1]){
			q=s[o];
			s[o]=s[o+1];
			s[o+1]=q;
		}
		
		
		
}
	
	
	
}


for(int i=1;i<=a;i++){
	cout<<s[i];
}
rean
}
