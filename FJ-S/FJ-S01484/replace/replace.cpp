#include <cstdio>
#define isfileio 1
#define filename "replace"
#define method 1
#if isfileio
#define programmefilein fopen(filename ".in", "r")
#define programmefileout fopen(filename ".out", "w")
#else
#define programmefilein stdin
#define programmefileout stdout
#endif
class fastInputHelper{
	char buf[1048577], *cn, *bufend;
	FILE *file;
	inline int getchar(){
		return cn != bufend ? *cn++ :
			(bufend = buf + fread(cn = buf, sizeof(char), 1048576llu, file), cn != bufend) ?
			*cn++ : ~0;
	}
	public:
		fastInputHelper(): cn(buf), bufend(buf), file(programmefilein){}
		~fastInputHelper(){
			fclose(file);
		}
		template<typename digit_type>
		fastInputHelper &operator>>(digit_type &x){
			int c = getchar();
			x = 0;
			while (c < 48 || c > 57){
				c = getchar();
				if (c == ~0){
					return *this;
				}
			}
			while (c > 47 && c < 58){
				x = x * 10 + (c & 15);
				c = getchar();
			}
			return *this;
		}
		fastInputHelper &readString(char *s, int &len){
			char *p = s;
			int c = getchar();
			while (c < 97 || c > 122){
				c = getchar();
				if (c == ~0){
					*p = 0;
					len = 0;
					return *this;
				}
			}
			while (c > 96 && c < 123){
				*p++ = c;
				c = getchar();
			}
			*p = 0;
			len = p - s;
			return *this;
		}
}fih;
class fastOutputHelper{
	char buf[1048577], *cn;
	const char *bufend;
	FILE *file;
	inline void putchar(int c){
		*cn++ = c;
		if (cn == bufend){
			fwrite(cn = buf, sizeof(char), 1048576llu, file);
		}
	}
	template<typename digit_type>
	void writedigit(const digit_type &x){
		if (x){
			writedigit(x / 10);
			putchar(x % 10 | 48);
		}
	}
	public:
		fastOutputHelper(): cn(buf), bufend(buf + 1048576llu), file(programmefileout){}
		~fastOutputHelper(){
			if (cn != buf){
				fwrite(buf, sizeof(char), cn - buf, file);
				cn = buf;
			}
			fclose(file);
		}
		template<typename digit_type>
		fastOutputHelper &operator<<(const digit_type &x){
			if (x > 0){
				writedigit(x / 10);
				putchar(x % 10 | 48);
			}
			else if(x == 0){
				putchar(48);
			}
			else{
				putchar('-');
				writedigit(-(x / 10));
				putchar(-(x % 10) | 48);
			}
			return *this;
		}
		inline fastOutputHelper &putc(int c){
			putchar(c);
		}
}foh;
#if method == 1
char s[5000004], t[5000004];
int len[400001], next[400001], match1[400001], match2[400001], n, q, lt1, lt2;
void kmpinit(const char *s, int lh, int l){
	int i = lh + 1, j = lh;
	next[i] = j;
	while (i < l){
		if (s[i] == s[j]){
			next[++i] = ++j;
		}
		else if(j ^ lh){
			j = next[j];
		}
		else{
			++i;
		}
	}
}
int kmp(const char *s, const char *t, int *eee, int lsh, int ls, int lth, int lt){
	int i = lth, j = lsh, id = 0;
	while (i < lt){
		while (i < lt && j < ls){
			if (t[i] == s[j]){
				++i;
				++j;
			}
			else if(j ^ lsh){
				j = next[j];
			}
			else{
				++i;
			}
		}
		if (j == ls){
			eee[id++] = (i - lth) - (j - lsh);
			j = next[j];
		}
	}
	return id;
}
int main(){
	fih >> n >> q;
	for (int i = 0; i < n; ++i){
		fih.readString(s + len[i << 1], len[i << 1 | 1]);
		len[i << 1 | 1] += len[i << 1];
		kmpinit(s, len[i << 1], len[i << 1 | 1]);
		fih.readString(s + len[i << 1 | 1], len[i + 1 << 1]);
		len[i + 1 << 1] += len[i << 1 | 1];
		kmpinit(s, len[i << 1 | 1], len[i + 1 << 1]);
	}
	while (q--){
		fih.readString(t, lt1);
		fih.readString(t + lt1, lt2);
		if (lt1 ^ lt2){
			foh.putc(48).putc(10);
		}
		lt2 += lt1;
		int ans = 0;
		for (int i = 0; i < n; ++i){
			int l1 = kmp(s, t, match1, len[i << 1], len[i << 1 | 1], 0, lt1),
			l2 = kmp(s, t, match2, len[i << 1 | 1], len[i + 1 << 1], lt1, lt2);
			int j = 0, k = 0, mc = 0;
			while (j < l1 && k < l2){
				if (match1[j] < match2[k]){
					++j;
				}
				else if(match1[j] > match2[k]){
					++k;
				}
				else{
					++j;
					++k;
					++mc;
				}
			}
			if (mc == 1){
				++ans;
			}
		}
		foh << ans;
		foh.putc(10);
	}
	return 0;
}
#endif
