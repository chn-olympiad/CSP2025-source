int n,m,v;
cin>>n>>m;
v=n*m;
int a[n][m];
int b[v],c;
for(int i=0;i<=v;i++){
	cin>>b[i];
}
c=b[0];
int q;
for(int i=0;i<=v;i++){
	for(int o=0;o<=v;o++){
		if(b[o]<b[o+1]){
			q=b[o];
			b[o]=b[o+1];
			b[o+1]=q;
		}
		
}

}
int x,y,z;
for(int i=0;i<=v;i++){
	y=i/m;
	x=i%m;
	
	if(b[i]==c){
		cout<<y<<" "<<x;
		
		
		
	}
	
	
}






