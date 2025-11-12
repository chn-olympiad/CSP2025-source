#include<bits/stdc++.h>
using namespace std;
void sz(){
	int a=0;
	cin>>a;
	int sum[a]={0};
	for(int s=0;s<a;s++){
		int b;
		cin>>b;
		int er[b][3]={0};
		int max=0,maxx=0;
		for(int i=0;i<b;i++){
			
			for(int j=0;j<3;j++){
				cin>>er[i][j];
				if(er[i][j]>=max){
					max=er[i][j];
					
				}
			}
			maxx+=max;
		}
		
		sum[s]=maxx;
	}
	
	for(int i=0;i<a;i++){
		cout<<sum[i]<<endl;
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	sz();
	return 0;


































































































































































































//ggggggggggggggggggggdsrggrehe
//herhrhdf
//athjky
//ajko'iluful,yuilsrlfyi
//hrhdshahlyfuil
//syjiraetyai6ukishhjyeueytjedyjyiwut
//ytitistraethyrstuykitufysrtaethyrjusruj
//srututrjsryjrsjyrjjsrjrtsjjukllllillligigyit5hujfg7 //ghgfdsfgdhfgdgfhdfgdshdfgfdgsdafdsafujinhwewbgfidhsfybhhdsolesesayfhcfriavrfujiavbbbbbbbbbgsrgsfjlshrjnrakjsjksj
//jstttttttttttttttttttttjsrrrrrrrrrrrrrrrrrrrrrrrrrrrrrriiiiiiiiiiiiiii
//jsrrrrrrrrrrrrrrrrrrrrrr6tiutujrujrjryjryjjryy fgfgc fg cfc //gfcfcfddxssazszadfgvhjnhiiiiiiidxsreazzzzzzzdxcf gvhbjnkml;jhbvgcfgv hhhhhhhhhhhhhhhhhhhc 
//ertttttttttttt3wrt
} 
